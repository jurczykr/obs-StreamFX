// AUTOGENERATED COPYRIGHT HEADER START
// Copyright (C) 2020-2023 Michael Fabian 'Xaymar' Dirks <info@xaymar.com>
// AUTOGENERATED COPYRIGHT HEADER END

#pragma once
#include "handler.hpp"

extern "C" {
#include "warning-disable.hpp"
#include <libavcodec/avcodec.h>
#include "warning-enable.hpp"
}

namespace streamfx::encoder::ffmpeg::handler {
	class prores_aw_handler : public handler {
		public:
		virtual ~prores_aw_handler(){};

		public /*factory*/:
		void get_defaults(obs_data_t* settings, const AVCodec* codec, AVCodecContext* context, bool hw_encode) override;

		virtual std::string_view get_help_url(const AVCodec* codec) override
		{
			return "https://github.com/Xaymar/obs-StreamFX/wiki/Encoder-FFmpeg-Apple-ProRes";
		};

		public /*support tests*/:
		bool has_pixel_format_support(ffmpeg_factory* instance) override;

		bool has_keyframe_support(ffmpeg_factory* instance) override;

		public /*settings*/:
		void get_properties(obs_properties_t* props, const AVCodec* codec, AVCodecContext* context, bool hw_encode) override;

		void update(obs_data_t* settings, const AVCodec* codec, AVCodecContext* context) override;

		void log_options(obs_data_t* settings, const AVCodec* codec, AVCodecContext* context) override;

		public /*instance*/:
		void override_colorformat(AVPixelFormat& target_format, obs_data_t* settings, const AVCodec* codec, AVCodecContext* context) override;
	};
} // namespace streamfx::encoder::ffmpeg::handler
