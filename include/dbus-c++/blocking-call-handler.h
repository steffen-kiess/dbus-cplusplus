/*
 *
 *  D-Bus++ - C++ bindings for D-Bus
 *
 *  Copyright (C) 2005-2007  Paolo Durante <shackan@gmail.com>
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */


#ifndef __DBUSXX_BLOCKING_CALL_HANDLER_H
#define __DBUSXX_BLOCKING_CALL_HANDLER_H

#include "api.h"

#include <dbus/dbus.h>

#include <memory>

namespace DBus
{

class DXXAPI BlockingCallHandler
{
public:
  BlockingCallHandler();
  ~BlockingCallHandler();

  virtual DBusMessage *dbus_connection_send_with_reply_and_block(
      DBusConnection *connection, DBusMessage *message,
      int timeout_milliseconds, DBusError *error);

  virtual void dbus_pending_call_block(DBusPendingCall *pending);

private:
  struct Private;
  RefPtrI<Private> _pvt;
};

} /* namespace DBus */

#endif//__DBUSXX_BLOCKING_CALL_HANDLER_H
