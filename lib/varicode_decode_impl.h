/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_PSK31_VARICODE_DECODE_IMPL_H
#define INCLUDED_PSK31_VARICODE_DECODE_IMPL_H

#include <psk31/varicode_decode.h>

namespace gr {
  namespace psk31 {

    class varicode_decode_impl : public varicode_decode
    {
    private:
      int state;
      int bits_eaten;
      char eat_bit(char bit);

    public:
      varicode_decode_impl();
      ~varicode_decode_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      // Where all the action really happens
      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);

      /*
       *  all varicode characters end with 1, so this table omits that.
       */
      static const char varicodes[512];
    };

  } // namespace psk31
} // namespace gr

#endif /* INCLUDED_PSK31_VARICODE_DECODE_IMPL_H */

