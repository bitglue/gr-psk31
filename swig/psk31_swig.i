/* -*- c++ -*- */

#define PSK31_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "psk31_swig_doc.i"

%{
#include "psk31/varicode_decode.h"
%}


%include "psk31/varicode_decode.h"
GR_SWIG_BLOCK_MAGIC2(psk31, varicode_decode);
