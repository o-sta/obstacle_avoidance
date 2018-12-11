
#ifndef INCLUDE_WHEEL_ODOMETRY_CLASS
#define INCLUDE_WHEEL_ODOMETRY_CLASS

#include"ros/ros.h"
#include <ros/callback_queue.h>
#include<odometry_publish/wheel_msg.h>
#include<odometry_publish/vel.h>

#include"time_class.h"

class wheel_odometry_class{
	private:
		int vr_i,vl_i;
		double vel_r,vel_l;//new_beego
		double vr_ord,vl_ord,vr,vl;
		double vx,vy,vz;
		double v,w;
		double position_x,position_z;
		double pre_position_x,pre_position_z;
		double yaw,pre_yaw;
		double dr;
		double dx,dz,dyaw;
		double pre_dx,pre_dz,pre_dyaw;
		bool first_process_flag;
		bool first_delta_process_flag;
		//const double d=0.276;//車輪幅
		const double d=0.290;//車輪幅 new_beego
		time_class tm_wlodm;
	public:
		wheel_odometry_class();
		bool is_cur_odometry(void);
		bool is_delta_odometry(void);
		void turn_first_process_flag(void);
		void turn_first_delta_process_flag(void);
		void subscribe_odometry(void);
		void subscribe_odometry_kai(void);
		void set_wheel_odometry(void);//<-use
		void get_cur_odometry(double& x,double& z,double& yw);//<-use
		void get_pre_odometry(double& x,double& z,double& yw);//<-use
		void get_delta_odometry(double& x,double& z,double& yw);//<-use
		double& get_wheel_velocity(void);
		virtual ~wheel_odometry_class();
		void set_delta_odometry(double& dt);//<-use
		virtual void define_variable(void);
		void set_current_velocity(void);
		void set_current_velocity_kai(void);
		double& get_velocity(void);
		double& get_angular_velocity(void);
		void set_velocity_X(void);
		double& get_velocity_x(void);
		double& get_velocity_y(void);
		double& get_velocity_z(void);
	protected:
		ros::NodeHandle nh_pub,nh_sub;
		ros::Publisher pub;
		ros::Subscriber sub;
		ros::NodeHandle nh2_sub;
		ros::Subscriber sub2;
		ros::CallbackQueue queue;
		ros::CallbackQueue queue2;
		virtual void set_velocity_and_angular_velocity(void);

		virtual void set_cur_odometry(void);
		virtual void set_pre_odometry(void);
		virtual void set_delta_position(double& dt);
		virtual void set_delta_orientetion(double& dt);
		virtual void wheel_odometry_callback(const odometry_publish::wheel_msg::ConstPtr& msg);
		virtual void new_wheel_odometry_callback(const odometry_publish::vel::ConstPtr& msg);
		void set_pre_delta_odometry(void);


};

#endif 


