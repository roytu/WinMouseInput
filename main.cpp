#pragma once

#include "gazeapi.h"
#include "MouseInput.h"
#include <windows.h>
#include <iostream>

// --- MyGaze definition
class MyGaze : public gtl::IGazeListener
{
    public:
        MyGaze();
        ~MyGaze();
    private:
        // IGazeListener
        void on_gaze_data( gtl::GazeData const & gaze_data );
    private:
        gtl::GazeApi m_api;
};

// --- MyGaze implementation
MyGaze::MyGaze()
{
    // Connect to the server in push mode on the default TCP port (6555)
    if( m_api.connect( true ) )
    {
        // Enable GazeData notifications
        m_api.add_listener( *this );
    }
}

MyGaze::~MyGaze()
{
    m_api.remove_listener( *this );
    m_api.disconnect();
}

void MyGaze::on_gaze_data( gtl::GazeData const & gaze_data )
{
    if( gaze_data.state & gtl::GazeData::GD_STATE_TRACKING_GAZE )
    {
        gtl::Point2D const & smoothedCoordinates = gaze_data.avg;
        float leftx = gaze_data.lefteye.raw.x;
        float lefty = gaze_data.lefteye.raw.y;
        float rightx = gaze_data.righteye.raw.x;
        float righty = gaze_data.righteye.raw.y;
		std::cout << leftx << " " << lefty << " " << rightx << " " << righty << std::endl;
    }
}