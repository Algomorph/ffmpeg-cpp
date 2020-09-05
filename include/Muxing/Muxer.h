#pragma once

#include "../ffmpeg.h"
#include "../StandardLibraryIncludes.h"


namespace ffmpegcpp {

	class OutputStream;

	class Muxer
	{
	public:

		Muxer(const std::string& url);
		~Muxer();

		void AddOutputStream(OutputStream* stream);

		void WritePacket(AVPacket* pkt);

		void Close();
		
		bool IsPrimed();


	private:

		void Open();
		
		std::vector<OutputStream*> outputStreams;
		std::vector<AVPacket*> packetQueue;

		AVOutputFormat* containerFormat;

		AVFormatContext* containerContext = nullptr;

		std::string fileName;

		void CleanUp();

		bool opened = false;
	};
}
