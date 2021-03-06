/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 */
#pragma once

#include <mcrouter/lib/carbon/TypeList.h>
#include <mcrouter/lib/network/CarbonMessageDispatcher.h>

#include "CarbonTestMessages.h"

namespace carbon {
namespace test {

namespace detail {

using CarbonTestRequestList = carbon::
    List<AnotherRequest, TestRequest, carbon::test2::util::YetAnotherRequest>;

} // detail

template <class OnRequest>
class CarbonTestRequestHandler
    : public facebook::memcache::CarbonMessageDispatcher<
          detail::CarbonTestRequestList,
          CarbonTestRequestHandler<OnRequest>,
          facebook::memcache::McServerRequestContext&&> {
 public:
  template <class... Args>
  explicit CarbonTestRequestHandler(Args&&... args)
      : onRequest_(std::forward<Args>(args)...) {}

  template <class Request>
  void onRequest(
      facebook::memcache::McServerRequestContext&& ctx,
      Request&& req) {
    onRequest_.onRequest(std::move(ctx), std::move(req));
  }

 private:
  OnRequest onRequest_;
};

} // test
} // carbon
