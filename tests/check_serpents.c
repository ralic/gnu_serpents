/*
Copyright 2016 Jochem Raat <jchmrt@riseup.net>

This file is part of serpents.

serpents is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your
option) any later version.

serpents is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with serpents.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdlib.h>
#include <check.h>

#include "check_input_buffer.h"
#include "check_board.h"
#include "check_color.h"
#include "check_high_score.h"

int
main (void)
{
  int number_failed;
  SRunner *sr;

  sr = srunner_create (input_buffer_suite ());
  srunner_add_suite (sr, board_suite ());
  srunner_add_suite (sr, color_suite ());
  srunner_add_suite (sr, high_score_suite ());

  srunner_set_log (sr, "test.log");
  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);
  srunner_free (sr);
  return number_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
