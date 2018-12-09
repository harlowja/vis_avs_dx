﻿#pragma once

#define DXUTERR_NODIRECT3D              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0901)
#define DXUTERR_NOCOMPATIBLEDEVICES     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0902)
#define DXUTERR_MEDIANOTFOUND           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0903)
#define DXUTERR_NONZEROREFCOUNT         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0904)
#define DXUTERR_CREATINGDEVICE          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0905)
#define DXUTERR_RESETTINGDEVICE         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0906)
#define DXUTERR_CREATINGDEVICEOBJECTS   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0907)
#define DXUTERR_RESETTINGDEVICEOBJECTS  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0908)
#define DXUTERR_INCORRECTVERSION        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0909)
#define DXUTERR_DEVICEREMOVED           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x090A)

#define XAUDIO2_E_INVALID_CALL          0x88960001
#define XAUDIO2_E_XMA_DECODER_ERROR     0x88960002
#define XAUDIO2_E_XAPO_CREATION_FAILED  0x88960003
#define XAUDIO2_E_DEVICE_INVALIDATED    0x88960004

#define XAPO_E_FORMAT_UNSUPPORTED MAKE_HRESULT(SEVERITY_ERROR, 0x897, 0x01)

#if WINVER <= 0x0603
// SDK version <= Win8.1. Support Win10 errors regardless.
#define DXGI_ERROR_NOT_CURRENT                    _HRESULT_TYPEDEF_(0x887A002EL)
#define DXGI_ERROR_HW_PROTECTION_OUTOFMEMORY      _HRESULT_TYPEDEF_(0x887A0030L)
#define DXGI_ERROR_DYNAMIC_CODE_POLICY_VIOLATION  _HRESULT_TYPEDEF_(0x887A0031L)
#define DXGI_ERROR_NON_COMPOSITED_UI              _HRESULT_TYPEDEF_(0x887A0032L)
#define DXGI_STATUS_PRESENT_REQUIRED              _HRESULT_TYPEDEF_(0x087A002FL)
#define DXGI_ERROR_CACHE_CORRUPT                  _HRESULT_TYPEDEF_(0x887A0033L)
#define DXGI_ERROR_CACHE_FULL                     _HRESULT_TYPEDEF_(0x887A0034L)
#define DXGI_ERROR_CACHE_HASH_COLLISION           _HRESULT_TYPEDEF_(0x887A0035L)
#define DXGI_ERROR_ALREADY_EXISTS                 _HRESULT_TYPEDEF_(0x887A0036L)

#define MF_E_HARDWARE_DRM_UNSUPPORTED                        _HRESULT_TYPEDEF_(0xC00D3706L)
#define MF_E_NET_COMPANION_DRIVER_DISCONNECT                 _HRESULT_TYPEDEF_(0xC00D4295L)
#define MF_E_TRANSFORM_STREAM_INVALID_RESOLUTION             _HRESULT_TYPEDEF_(0xC00D6D79L)
#define MF_E_TRANSFORM_ASYNC_MFT_NOT_SUPPORTED               _HRESULT_TYPEDEF_(0xC00D6D7AL)
#define MF_E_TRANSFORM_EXATTRIBUTE_NOT_SUPPORTED             _HRESULT_TYPEDEF_(0xC00D6D7CL)
#define MF_E_HDCP_AUTHENTICATION_FAILURE                     _HRESULT_TYPEDEF_(0xC00D7188L)
#define MF_E_HDCP_LINK_FAILURE                               _HRESULT_TYPEDEF_(0xC00D7189L)
#define MF_E_UNSUPPORTED_CAPTURE_DEVICE_PRESENT              _HRESULT_TYPEDEF_(0xC00DABEDL)
#define MF_E_TIMELINECONTROLLER_UNSUPPORTED_SOURCE_TYPE      _HRESULT_TYPEDEF_(0xC00DAFC8L)
#define MF_E_TIMELINECONTROLLER_NOT_ALLOWED                  _HRESULT_TYPEDEF_(0xC00DAFC9L)
#define MF_E_TIMELINECONTROLLER_CANNOT_ATTACH                _HRESULT_TYPEDEF_(0xC00DAFCAL)
#define MF_E_MEDIA_EXTENSION_APPSERVICE_CONNECTION_FAILED    _HRESULT_TYPEDEF_(0xC00DB3B0L)
#define MF_E_MEDIA_EXTENSION_APPSERVICE_REQUEST_FAILED       _HRESULT_TYPEDEF_(0xC00DB3B1L)
#define MF_E_MEDIA_EXTENSION_PACKAGE_INTEGRITY_CHECK_FAILED  _HRESULT_TYPEDEF_(0xC00DB3B2L)
#define MF_E_MEDIA_EXTENSION_PACKAGE_LICENSE_INVALID         _HRESULT_TYPEDEF_(0xC00DB3B3L)
#endif