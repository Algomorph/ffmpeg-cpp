#pragma once

#include "ffmpeg.h"
#include "std.h"

#include "Demuxing/AudioInputStream.h"
#include "Demuxing/VideoInputStream.h"
#include "Demuxing/InputStream.h"
#include "Sources/InputSource.h"

namespace ffmpegcpp
{
	struct StreamInfo
	{
		int streamId;
		AVCodec* codec;
		AVStream* stream;
	};

	class Demuxer : public InputSource
	{
	public:

		Demuxer(const char* fileName);
		Demuxer(const char* fileName, AVInputFormat* inputFormat, AVDictionary *inputFormatOptions);
		~Demuxer();

		void EncodeBestAudioStream(AudioFrameSink* frameSink);
		void EncodeBestVideoStream(VideoFrameSink* frameSink);

		void EncodeAudioStream(int streamId, AudioFrameSink* frameSink);
		void EncodeVideoStream(int streamId, VideoFrameSink* frameSink);

		std::vector<StreamInfo> GetAudioStreamInfo();
		std::vector<StreamInfo> GetVideoStreamInfo();

		void Start();

	private:

		const char* fileName;

		std::vector<StreamInfo> GetStreamInfo(AVMediaType mediaType);
		StreamInfo CreateInfo(int streamIndex, AVStream* stream, AVCodec* codec);

		InputStream** inputStreams = nullptr;

		AVFormatContext* containerContext = nullptr;
		AVPacket* pkt = nullptr;

		void DecodePacket();

		void CleanUp();
	};
}