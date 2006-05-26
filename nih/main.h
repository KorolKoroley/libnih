/* libnih
 *
 * Copyright © 2006 Scott James Remnant <scott@netsplit.com>.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef NIH_MAIN_H
#define NIH_MAIN_H

#include <nih/macros.h>


/**
 * nih_main_init:
 * @argv0: program name from arguments.
 *
 * Should be called at the beginning of #main to initialise the various
 * global variables exported from this module.  Wraps #nih_main_init_full
 * passing values set by Autoconf AC_INIT and AC_COPYRIGHT macros.
 **/
#ifndef PACKAGE_COPYRIGHT
# define PACKAGE_COPYRIGHT NULL
#endif
#define nih_main_init(argv0) \
	nih_main_init_full (argv0, PACKAGE_NAME, PACKAGE_VERSION, \
			    PACKAGE_BUGREPORT, PACKAGE_COPYRIGHT)


NIH_BEGIN_EXTERN

/* Program name, taken from argv[0] */
const char *program_name;

/* Package name, taken from configure */
const char *package_name;

/* Package version, taken from configure */
const char *package_version;

/* Package copyright, taken from configure */
const char *package_copyright;

/* Package bug report address, taken from configure */
const char *package_bugreport;


void        nih_main_init_full      (const char *argv0,
				     const char *package,
				     const char *version,
				     const char *bugreport,
				     const char *copyright);

const char *nih_main_package_string (void);
void        nih_main_suggest_help   (void);
void        nih_main_version        (void);

NIH_END_EXTERN

#endif /* NIH_MAIN_H */