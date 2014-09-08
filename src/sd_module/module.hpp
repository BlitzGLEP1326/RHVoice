/* Copyright (C) 2012  Olga Yakovleva <yakovleva.o.v@gmail.com> */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef RHVOICE_SD_MODULE_HPP
#define RHVOICE_SD_MODULE_HPP

#include <string>
#include <map>
#include "command.hpp"

namespace RHVoice
{
  namespace sd
  {
    class module: public command
    {
    public:
      module();

    private:
      action_t execute();
      void close();

      typedef std::map<std::string,cmd_ptr> cmd_map;

      template<class T>
      void register_subcommand(const std::string& name)
      {
        subcommands[name]=cmd_ptr(new T);
      }

      template<class T,typename A>
      void register_subcommand(const A& arg,const std::string& name)
      {
        subcommands[name]=cmd_ptr(new T(arg));
      }

      cmd_map subcommands;
    };
  }
}
#endif