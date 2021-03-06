#include "tracklogger.hpp"
#include "tracker.h"

TrackLogger::~TrackLogger() {}

void TrackLogger::reset_dt()
{
    t.start();
}

void TrackLogger::write_dt()
{
	//below is modified by MosQuito
    //const double et = t.elapsed_seconds();
	const double dt = t.timestamp();
	//end
    write(&dt, 1);
}

void TrackLoggerCSV::handle_first_col_sep()
{
    if (!first_col)
        out.put(',');
    first_col = false;
}

void TrackLoggerCSV::write(const char *s)
{
    handle_first_col_sep();
    out << s;
}


void TrackLoggerCSV::write(const double *p, int n)
{
    handle_first_col_sep();
    for (int i = 0; i < n-1; ++i)
    {
        out << p[i];
        out.put(',');
    }
	
	//below is modified by MosQuito
	out.precision(3);
    out << std::fixed << p[n-1];
	//end
}


void TrackLoggerCSV::next_line()
{
    out << std::endl;
    first_col = true;
}

