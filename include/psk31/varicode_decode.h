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


#ifndef INCLUDED_PSK31_VARICODE_DECODE_H
#define INCLUDED_PSK31_VARICODE_DECODE_H

#include <psk31/api.h>
#include <gr_block.h>

namespace gr {
  namespace psk31 {

    /*!
     * \brief <+description of block+>
     * \ingroup psk31
     *
     */
    class PSK31_API varicode_decode : virtual public gr_block
    {
    public:
       typedef boost::shared_ptr<varicode_decode> sptr;

       /*!
        * \brief Return a shared_ptr to a new instance of psk31::varicode_decode.
        *
        * To avoid accidental use of raw pointers, psk31::varicode_decode's
        * constructor is in a private implementation
        * class. psk31::varicode_decode::make is the public interface for
        * creating new instances.
        */
       static sptr make();
    };

  } // namespace psk31
} // namespace gr

#endif /* INCLUDED_PSK31_VARICODE_DECODE_H */

