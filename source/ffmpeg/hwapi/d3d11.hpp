// AUTOGENERATED COPYRIGHT HEADER START
// Copyright (C) 2020-2023 Michael Fabian 'Xaymar' Dirks <info@xaymar.com>
// Copyright (C) 2022 lainon <GermanAizek@yandex.ru>
// AUTOGENERATED COPYRIGHT HEADER END

#pragma once
#include "base.hpp"

#include "warning-disable.hpp"
#include <atlutil.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <dxgi.h>
#include "warning-enable.hpp"

namespace streamfx::ffmpeg::hwapi {
	class d3d11 : public streamfx::ffmpeg::hwapi::base {
		typedef HRESULT(__stdcall* CreateDXGIFactory_t)(REFIID, void**);
		typedef HRESULT(__stdcall* CreateDXGIFactory1_t)(REFIID, void**);
		typedef HRESULT(__stdcall* D3D11CreateDevice_t)(IDXGIAdapter*, D3D_DRIVER_TYPE, HMODULE, UINT, CONST D3D_FEATURE_LEVEL*, UINT, UINT, ID3D11Device**, D3D_FEATURE_LEVEL*, ID3D11DeviceContext**);

		HMODULE              _dxgi_module;
		CreateDXGIFactory_t  _CreateDXGIFactory;
		CreateDXGIFactory1_t _CreateDXGIFactory1;

		HMODULE             _d3d11_module;
		D3D11CreateDevice_t _D3D11CreateDevice;

		ATL::CComPtr<IDXGIFactory1> _dxgifactory;

		public:
		d3d11();
		virtual ~d3d11();

		virtual std::list<hwapi::device> enumerate_adapters() override;

		virtual std::shared_ptr<hwapi::instance> create(const hwapi::device& target) override;

		virtual std::shared_ptr<hwapi::instance> create_from_obs() override;
	};

	class d3d11_instance : public streamfx::ffmpeg::hwapi::instance {
		ATL::CComPtr<ID3D11Device>        _device;
		ATL::CComPtr<ID3D11DeviceContext> _context;

		public:
		d3d11_instance(ATL::CComPtr<ID3D11Device> device);
		virtual ~d3d11_instance();

		virtual AVBufferRef* create_device_context() override;

		virtual std::shared_ptr<AVFrame> allocate_frame(AVBufferRef* frames) override;

		virtual void copy_from_obs(AVBufferRef* frames, uint32_t handle, uint64_t lock_key, uint64_t* next_lock_key, std::shared_ptr<AVFrame> frame) override;

		virtual std::shared_ptr<AVFrame> avframe_from_obs(AVBufferRef* frames, uint32_t handle, uint64_t lock_key, uint64_t* next_lock_key) override;
	};
} // namespace streamfx::ffmpeg::hwapi
