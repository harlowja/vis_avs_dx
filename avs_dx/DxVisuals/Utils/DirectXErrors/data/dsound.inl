﻿// -------------------------------------------------------------
// dsound.h error codes
// -------------------------------------------------------------
// CHK_ERR(DS_OK, "")
CHK_ERR(DS_NO_VIRTUALIZATION, "The call succeeded, but we had to substitute the 3D algorithm")
CHK_ERR(DSERR_ALLOCATED, "The call failed because resources (such as a priority level) were already being used by another caller")
CHK_ERR(DSERR_CONTROLUNAVAIL, "The control (vol, pan, etc.) requested by the caller is not available")
// CHK_ERR(DSERR_INVALIDPARAM, "DSERR_INVALIDPARAM")
CHK_ERR(DSERR_INVALIDCALL, "This call is not valid for the current state of this object")
// CHK_ERR(DSERR_GENERIC, "DSERR_GENERIC")
CHK_ERR(DSERR_PRIOLEVELNEEDED, "The caller does not have the priority level required for the function to succeed")
// CHK_ERR(DSERR_OUTOFMEMORY, "Not enough free memory is available to complete the operation")
CHK_ERR(DSERR_BADFORMAT, "The specified WAVE format is not supported")
// CHK_ERR(DSERR_UNSUPPORTED, "DSERR_UNSUPPORTED")
CHK_ERR(DSERR_NODRIVER, "No sound driver is available for use")
CHK_ERR(DSERR_ALREADYINITIALIZED, "This object is already initialized")
// CHK_ERR(DSERR_NOAGGREGATION, "DSERR_NOAGGREGATION")
CHK_ERR(DSERR_BUFFERLOST, "The buffer memory has been lost, and must be restored")
CHK_ERR(DSERR_OTHERAPPHASPRIO, "Another app has a higher priority level, preventing this call from succeeding")
CHK_ERR(DSERR_UNINITIALIZED, "This object has not been initialized")
// CHK_ERR(DSERR_NOINTERFACE, "DSERR_NOINTERFACE")
// CHK_ERR(DSERR_ACCESSDENIED, "DSERR_ACCESSDENIED")
CHK_ERR(DSERR_BUFFERTOOSMALL, "Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds")
CHK_ERR(DSERR_DS8_REQUIRED, "Attempt to use DirectSound 8 functionality on an older DirectSound object")
CHK_ERR(DSERR_SENDLOOP, "A circular loop of send effects was detected")
CHK_ERR(DSERR_BADSENDBUFFERGUID, "The GUID specified in an audiopath file does not match a valid MIXIN buffer")
CHK_ERR(DSERR_OBJECTNOTFOUND, "The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)")

CHK_ERR(DSERR_FXUNAVAILABLE, "Requested effects are not available")