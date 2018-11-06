#include<vfh+.h>

vfh::vfh(float width,float height,float resolution)
    {//,it(nh_pub){
	//マップデータの設定と初期化
	map_wf=width;
	map_hf=height;
	reso=resolution;
	map_wi=(int)(map_wf/resolution);
	map_hi=(int)(map_hf/resolution);
	cr=std::sqrt(2)*reso/2;
	std::cout<<"vfh\n";
	
	//cv::Mat
	//int
	cv::Mat m_temp = cv::Mat::zeros(cv::Size(map_hi,map_wi), CV_8UC1);
	grid_map=m_temp.clone();
	
    //polor histogram range and resolution
    min_range=-45;
    max_range=45;
    reso_range=1;
	//std::vector<float> ph;
	ph.resize((max_range-min_range)/reso_range);
	//debug
	debug_image = cv::Mat::zeros(cv::Size(map_hi,map_wi), CV_8UC3);
	pub=nh_pub.advertise<sensor_msgs::Image>("grid_image",1);	
}
vfh::vfh()
	:width(8.0),height(8.0),resolution(0.05)
    {//,it(nh_pub){
	//マップデータの設定と初期化
	map_wf=width;
	map_hf=height;
	reso=resolution;
	map_wi=(int)(map_wf/resolution);
	map_hi=(int)(map_hf/resolution);
	cr=std::sqrt(2)*reso/2;
	std::cout<<"vfh\n";
	
	//cv::Mat
	//int
	cv::Mat m_temp = cv::Mat::zeros(cv::Size(map_hi,map_wi), CV_8UC1);
	grid_map=m_temp.clone();
	
    //polor histogram range and resolution
    min_range=-45;
    max_range=45;
    reso_range=1;
	//std::vector<float> ph;
	ph.resize((max_range-min_range)/reso_range);
	//debug
	debug_image = cv::Mat::zeros(cv::Size(map_hi,map_wi), CV_8UC3);
	pub=nh_pub.advertise<sensor_msgs::Image>("grid_image",1);	
}
vfh::~vfh()
{
	grid_map.release();
	debug_image.release();
}

