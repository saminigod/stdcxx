// checking for std::nothrow

/***************************************************************************
 *
 * Licensed to the Apache Software  Foundation (ASF) under one or more
 * contributor  license agreements.  See  the NOTICE  file distributed
 * with  this  work  for  additional information  regarding  copyright
 * ownership.   The ASF  licenses this  file to  you under  the Apache
 * License, Version  2.0 (the  License); you may  not use  this file
 * except in  compliance with the License.   You may obtain  a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the  License is distributed on an  "AS IS" BASIS,
 * WITHOUT  WARRANTIES OR CONDITIONS  OF ANY  KIND, either  express or
 * implied.   See  the License  for  the  specific language  governing
 * permissions and limitations under the License.
 *
 * Copyright 1999-2007 Rogue Wave Software, Inc.
 * 
 **************************************************************************/


// will fail if namespaces aren't supported
namespace std {

struct nothrow_t { };

extern const nothrow_t nothrow;

}   // std


// force a failure by using the same name for an object of a diferent
// type than std:nothrow_t if namespace std isn't honored
const std::nothrow_t *nothrow = &std::nothrow;


int main (int argc, char *argv[])
{
    (void)&argv;

    // foil clever optimizers
    if (argc > 2)
        nothrow = 0;

    // will fail at link-time if std::nothrow is not defined
    // in the compiler support library
    return !(0 != nothrow);
}
