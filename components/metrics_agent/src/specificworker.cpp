/*
 *    Copyright (C) 2021 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(TuplePrx tprx, bool startup_check) : GenericWorker(tprx)
{
	this->startup_check_flag = startup_check;
    QLoggingCategory::setFilterRules("*.debug=false\n");
}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{
	std::cout << "Destroying SpecificWorker" << std::endl;
	G->write_to_json_file("./"+agent_name+".json");
	G.reset();
}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{


	agent_name = params["agent_name"].value;
	agent_id = stoi(params["agent_id"].value);

	tree_view = params["tree_view"].value == "true";
	graph_view = params["graph_view"].value == "true";
	qscene_2d_view = params["2d_view"].value == "true";
	osg_3d_view = params["3d_view"].value == "true";

	return true;
}

void SpecificWorker::initialize(int period)
{
	std::cout << "Initialize worker" << std::endl;
	this->Period = period;
	if(this->startup_check_flag)
	{
		this->startup_check();
	}
	else
	{
		timer.start(Period);
		// create graph
		G = std::make_shared<DSR::DSRGraph>(0, agent_name, agent_id, ""); // Init nodes
		std::cout<< __FUNCTION__ << "Graph loaded" << std::endl;  

		//dsr update signals
		connect(G.get(), &DSR::DSRGraph::update_node_signal, this, &SpecificWorker::modify_node_slot);
		connect(G.get(), &DSR::DSRGraph::update_edge_signal, this, &SpecificWorker::modify_edge_slot);
		connect(G.get(), &DSR::DSRGraph::update_node_attr_signal, this, &SpecificWorker::modify_attrs_slot);
		connect(G.get(), &DSR::DSRGraph::del_edge_signal, this, &SpecificWorker::del_edge_slot);
		connect(G.get(), &DSR::DSRGraph::del_node_signal, this, &SpecificWorker::del_node_slot);

		// Graph viewer
		using opts = DSR::DSRViewer::view;
		int current_opts = 0;
		opts main = opts::none;
		if(tree_view)
		{
		    current_opts = current_opts | opts::tree;
		}
		if(graph_view)
		{
		    current_opts = current_opts | opts::graph;
		    main = opts::graph;
		}
		if(qscene_2d_view)
		{
		    current_opts = current_opts | opts::scene;
		}
		if(osg_3d_view)
		{
		    current_opts = current_opts | opts::osg;
		}
		graph_viewer = std::make_unique<DSR::DSRViewer>(this, G, current_opts, main);
		setWindowTitle(QString::fromStdString(agent_name + "-") + QString::number(agent_id));

		this->Period = period;
		timer.start(Period);

        // Inner Api
        inner_eigen = G->get_inner_eigen_api();


        /// Esto solo vale para personas que ya estén dentro del escenario y no desaparezcan ni se
        /// creen otras nuevas
        if(auto humans = G->get_nodes_by_type(person_type_name); not humans.empty())
        {
            for( const auto &human : humans)
            {
                //QVector<QPointF> person_points;
                //people_points.append(person_points);
                QVector<float> person_distance;
                people_distances.append(person_distance);
            }
        }

        if(auto personal_spaces = G->get_nodes_by_type(personal_space_type_name); not personal_spaces.empty())
        {
            for( const auto &ps : personal_spaces)
            {
                const auto person_id_o = G->get_attrib_by_name<person_id_att>(ps);



                //Meter el polígono y los contadores en la posición person_id
                //people_distances.operator[](person_id_o.value()).append(distance);

                //VECTOR GAUSIANAS, SOCIAL ZONE
                QPolygonF social;

                // Get social zone polygon
                const auto social_x_o = G->get_attrib_by_name<ps_social_x_pos_att>(ps);
                const auto social_y_o = G->get_attrib_by_name<ps_social_y_pos_att>(ps);
                if( social_x_o.has_value() and social_y_o.has_value())
                {

                    const std::vector<float> &social_x = social_x_o.value().get();
                    const std::vector<float> &social_y = social_y_o.value().get();
                    for(auto &&[point_x,point_y] : iter::zip(social_x, social_y))
                    {
                        QPointF point(point_x,point_y);
                        social.append(point);
                    }

                }

                people_social_spaces.operator[](person_id_o.value()).append(social);

                //VECTOR GAUSIANAS, PERSONAL ZONE
                QPolygonF personal;

                // Get social zone polygon
                const auto personal_x_o = G->get_attrib_by_name<ps_personal_x_pos_att>(ps);
                const auto personal_y_o = G->get_attrib_by_name<ps_personal_y_pos_att>(ps);
                if( personal_x_o.has_value() and personal_y_o.has_value())
                {

                    const std::vector<float> &personal_x = personal_x_o.value().get();
                    const std::vector<float> &personal_y = personal_y_o.value().get();
                    for(auto &&[point_x,point_y] : iter::zip(personal_x, personal_y))
                    {
                        QPointF point(point_x,point_y);
                        personal.append(point);
                    }

                }

                people_personal_spaces.operator[](person_id_o.value()).append(personal);

                //VECTOR GAUSIANAS, INTIMATE ZONE
                QPolygonF intimate;

                // Get social zone polygon
                const auto intimate_x_o = G->get_attrib_by_name<ps_intimate_x_pos_att>(ps);
                const auto intimate_y_o = G->get_attrib_by_name<ps_intimate_y_pos_att>(ps);
                if( intimate_x_o.has_value() and intimate_y_o.has_value())
                {

                    const std::vector<float> &intimate_x = intimate_x_o.value().get();
                    const std::vector<float> &intimate_y = intimate_y_o.value().get();
                    for(auto &&[point_x,point_y] : iter::zip(intimate_x, intimate_y))
                    {
                        QPointF point(point_x,point_y);
                        intimate.append(point);
                    }

                }

                people_intimate_spaces.operator[](person_id_o.value()).append(intimate);

            }
        }
        intention_flag = false;
	}

}

void SpecificWorker::compute()
{
    if(auto mind = G->get_node(robot_mind_name); mind.has_value())
    {
        if (auto intention = G->get_node(current_intention_name); intention.has_value())
        {
            intention_flag = true;

            auto robot_pose = inner_eigen->transform(world_name, robot_name).value();
            QPointF robot_point(robot_pose.x(),robot_pose.y());
            qInfo() << __FUNCTION__ << " Robot posicion X: " << robot_point.x() << " posicion Y: " << robot_point.y();

            robot_points.append(robot_point);
            qInfo() << __FUNCTION__ << " TAMANIO: " << robot_points.length();


            if(auto humans = G->get_nodes_by_type(person_type_name); not humans.empty())
            {
                for( const auto &human : humans)
                {
                    const auto person_id_o = G->get_attrib_by_name<person_id_att>(human);

                    auto person_pose = inner_eigen->transform(world_name, human.name()).value();

                    float distance = G->get_attrib_by_name<distance_to_robot_att>(human).value();
                    distance = sqrt(pow(robot_pose.x()-person_pose.x(),2)+ pow(robot_pose.y()-person_pose.y(),2));
                    people_distances.operator[](person_id_o.value()).append(distance);
                    if(auto human_update = G->get_node(human.name());human_update.has_value()){
                        G->add_or_modify_attrib_local<distance_to_robot_att>(human_update.value(),distance);
                        if(G->update_node(human_update.value())){
                            std::cout << __FUNCTION__ << "Node \"human\" succesfully updated in G" << std::endl;
                        }else{
                            std::cout << __FILE__ << __FUNCTION__ << "Fatal error updating 'human' node" << std::endl;
                        }
                    }

                    if(people_social_spaces.operator[](person_id_o.value()).containsPoint(robot_point, Qt::OddEvenFill))
                    {
                        int cont = social_cont.operator[](person_id_o.value());
                        cont++;
                        social_cont.operator[](person_id_o.value()) = cont;
                    }

                    if(people_personal_spaces.operator[](person_id_o.value()).containsPoint(robot_point, Qt::OddEvenFill))
                    {
                        int cont = personal_cont.operator[](person_id_o.value());
                        cont++;
                        personal_cont.operator[](person_id_o.value()) = cont;
                    }

                    if(people_intimate_spaces.operator[](person_id_o.value()).containsPoint(robot_point, Qt::OddEvenFill))
                    {
                        int cont = intimate_cont.operator[](person_id_o.value());
                        cont++;
                        intimate_cont.operator[](person_id_o.value()) = cont;
                    }


                   /* QPointF person_point(person_pose.x(),person_pose.y());
                    people_points.value(person_id_o.value()).append(person_point);
                    qInfo() << __FUNCTION__ << " Person " << person_id_o.value() << "posicion X: " << person_point.x() << " posicion Y: " << person_point.y();*/
                }
            }



        }else
        {
            if (intention_flag){
                qInfo() << __FUNCTION__ << " TERMINADOOOOOOOOOOOOO ";

                /// MÉTRICAS ROBOT
                ofstream file("robotpose1.txt", ofstream::out);
                for (auto p: robot_points)
                    file<<p.x() << " " <<p.y()<< endl;

                file.close();


                robot_points.clear();/// MÉTRICAS

                /// MÉTRICAS HUMANOS

                if(auto humans = G->get_nodes_by_type(person_type_name); not humans.empty())
                {
                    ofstream file2("personpose.txt", ofstream::out);

                    //for( const auto &human : humans)
                    //{
                    int cont =0;
                    for (auto p: people_distances)
                    {
                        file2<<"TAMANIO: "<<p.size()<< endl;
                        for(auto d: p){
                            file2<<d<< endl;
                        }
                        file2 << endl;
                        people_distances.operator[](cont).clear();
                        cont++;
                    }


                        //auto person_pose = inner_eigen->transform(world_name, human.name()).value();

                        //qInfo() << __FUNCTION__ << " Person posicion X: " << person_pose.x() << " posicion Y: " << person_pose.y();
                        //file2<<person_pose.x() << " " <<person_pose.y()<< " " << 0 << endl;
                    //}
                    qInfo() << __FUNCTION__ << " PERSONAS TAMANIO: " << humans.size();
                    file2.close();
                }

                //people_points.clear();/// MÉTRICAS
                intention_flag = false;

                qInfo() << __FUNCTION__ << "CONT SOCIAL: " << social_cont.operator[](0);
                qInfo() << __FUNCTION__ << "CONT PERSONAL: " << personal_cont.operator[](0);
                qInfo() << __FUNCTION__ << "CONT INTIMO: " << intimate_cont.operator[](0);
            }
        }

    }

	
	
}

int SpecificWorker::startup_check()
{
	std::cout << "Startup check" << std::endl;
	QTimer::singleShot(200, qApp, SLOT(quit()));
	return 0;
}




