/* -*- c++ -*- */
/* 
 * Copyright 2013 Phil Frost.
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_io_signature.h>
#include "varicode_decode_impl.h"

namespace gr {
  namespace psk31 {
    const char varicode_decode_impl::varicodes[512] = {
      ' ', 'e', 't', 'o', '\xff', 'a', 'i', 'n', '\xff', '\xff', 'r', 's',
      '\xff', 'l', '\n', '\r', '\xff', '\xff', '\xff', '\xff', '\xff', 'h', 'd',
      'c', '\xff', '\xff', '-', 'u', '\xff', 'm', 'f', 'p', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '=', '.',
      '\xff', 'g', 'y', 'b', '\xff', '\xff', '\xff', '\xff', '\xff', 'w', 'T',
      'S', '\xff', '\xff', ',', 'E', '\xff', 'v', 'A', 'I', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', 'O', 'C', 'R', '\xff', '\xff', 'D', '0', '\xff', 'M', '1', 'k',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', 'P', 'L', '\xff', 'F', 'N', 'x', '\xff', '\xff', '\xff', '\xff',
      '\xff', 'B', '2', '\t', '\xff', '\xff', ':', ')', '\xff', '(', 'G', '3',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', 'H', 'U', '\xff', '5',
      'W', '"', '\xff', '\xff', '\xff', '\xff', '\xff', '6', '_', '*', '\xff',
      '\xff', 'X', '4', '\xff', 'Y', 'K', '\'', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '8', '7',
      '/', '\xff', '\xff', 'V', '9', '\xff', '|', ';', 'q', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', 'z', '>',
      '\xff', '$', 'Q', '+', '\xff', '\xff', '\xff', '\xff', '\xff', 'j', '<',
      '\\', '\xff', '\xff', '#', '[', '\xff', ']', 'J', '!', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\x00', 'Z', '?', '\xff', '\xff', '}', '{', '\xff', '&',
      '@', '^', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '%', '~', '\xff', '\x01', '\x0c', '`', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\x04', '\x02', '\x06', '\xff', '\xff', '\x11',
      '\x10', '\xff', '\x1e', '\x07', '\x08', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\x1b', '\x17', '\xff', '\x14', '\x1c', '\x05', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\x15', '\x16', '\x0b', '\xff', '\xff',
      '\x0e', '\x03', '\xff', '\x18', '\x19', '\x1f', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\x0f', '\x12', '\x13', '\xff', '\xff', '\x7f', '\x1a', '\xff', '\x1d',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff',
      '\xff', '\xff', '\xff', '\xff', '\xff', '\xff', '\xff'};

    varicode_decode::sptr
    varicode_decode::make()
    {
      return gnuradio::get_initial_sptr (new varicode_decode_impl());
    }

    /*
     * The private constructor
     */
    varicode_decode_impl::varicode_decode_impl()
      : gr_block("varicode_decode",
		      gr_make_io_signature(1, 1, sizeof (char)),
		      gr_make_io_signature(1, 1, sizeof (char))),
      state(0),
      bits_eaten(0)
    {}

    /*
     * Our virtual destructor.
     */
    varicode_decode_impl::~varicode_decode_impl()
    {
    }

    void
    varicode_decode_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /*
       *  I'm guessing here that on average a varicode character takes 8 bits
       */
      ninput_items_required[0] = noutput_items * 1;
    }

    int
    varicode_decode_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        const char *in = (const char *) input_items[0];
        char *out = (char *) output_items[0];
        size_t input_items_to_eat = ninput_items[0];
        size_t chars_decoded = 0;
        char last_char_decoded;

        for(size_t i=0; (i < input_items_to_eat) && (chars_decoded < noutput_items); i+=1) {
          last_char_decoded = eat_bit(in[i]);
          if (last_char_decoded != -1) {
            out[chars_decoded++] = last_char_decoded;
          }
        }
        // Tell runtime system how many input items we consumed on each input
        // stream.
        consume_each (input_items_to_eat);

        // Tell runtime system how many output items we produced.
        return chars_decoded;
    }

    char
    varicode_decode_impl::eat_bit(char bit)
    {
      /* shift the bit into state */
      state <<= 1;
      if (bit) {
        state |= 1;
      }
      bits_eaten += 1;

      if (bits_eaten < 2) {
        /* can't be done with a character if there have been less than two bits
         * received */
        return -1;
      }

      if (state & 3) {
        /* can't be done with a character if the last two bits weren't zeros */
        return -1;
      }

      /* XXX no character can begin with a zero, but that's not tested yet. */

      /* XXX also no character can end with a zero, but that's not tested yet.
       * either. */

      /* we are done with a character. Reset the state, and return the
       * character, if valid. */

      // XXX potential access out of bounds here, test!
      char result = varicodes[state >> 3];
      state = bits_eaten = 0;
      return result;
    }

  } /* namespace psk31 */
} /* namespace gr */

