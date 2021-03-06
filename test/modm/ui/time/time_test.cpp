/*
 * Copyright (c) 2012, Fabian Greif
 * Copyright (c) 2014, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#include <modm/ui/time/time.hpp>

#include "time_test.hpp"

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToUnixTime()
{
	modm::Date date;
	
	// 01:46:40 UTC on 9 September 2001
	date.second = 40;
	date.minute = 46;
	date.hour = 1;
	date.day = 9;
	date.month = 8;
	date.year = 2001 - 1900;
	date.dayOfTheWeek = 0;
	date.dayOfTheYear = 251;
	
	TEST_ASSERT_EQUALS(date.toUnixTimestamp(), static_cast<uint32_t>(1000000000UL));
}

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToUnixTime2()
{
	modm::Date date;
	
	//13:37:04 UTC on 10 January 2004
	date.second = 4;
	date.minute = 37;
	date.hour = 13;
	date.day = 10;
	date.month = 0;
	date.year = 2004 - 1900;
	date.dayOfTheWeek = 6;
	date.dayOfTheYear = 9;
	
	TEST_ASSERT_EQUALS(date.toUnixTimestamp(), static_cast<uint32_t>(1073741824UL));
}

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToUnixTime3()
{
	modm::Date date;
	
	// 03:42:01 UTC on 27 July 2011
	date.second = 1;
	date.minute = 42;
	date.hour = 3;
	date.day = 27;
	date.month = 6;
	date.year = 2011 - 1900;
	date.dayOfTheWeek = 3;
	date.dayOfTheYear = 207;
	
	TEST_ASSERT_EQUALS(date.toUnixTimestamp(), static_cast<uint32_t>(1311738121UL));
}

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToUnixTime4()
{
	modm::Date date;
	
	date.second = 44;
	date.minute = 14;
	date.hour = 1;
	date.day = 2;
	date.month = 3;
	date.year = 2012 - 1900;
	date.dayOfTheWeek = 1;
	date.dayOfTheYear = 92;
	
	TEST_ASSERT_EQUALS(date.toUnixTimestamp(), static_cast<uint32_t>(1333329284UL));
}

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToUnixTime5()
{
	modm::Date date;
	
	// 00:37:33 UTC on 21 July 2069
	date.second = 33;
	date.minute = 37;
	date.hour = 0;
	date.day = 21;
	date.month = 6;
	date.year = 2069 - 1900;
	date.dayOfTheWeek = 0;
	date.dayOfTheYear = 201;
	
	TEST_ASSERT_EQUALS(date.toUnixTimestamp(), static_cast<uint32_t>(3141592653UL));
}

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToDate()
{
	modm::Date date;
	modm::UnixTime(1000000000UL).toDate(&date);
	
	TEST_ASSERT_EQUALS(date.second, 40);
	TEST_ASSERT_EQUALS(date.minute, 46);
	TEST_ASSERT_EQUALS(date.hour, 1);
	TEST_ASSERT_EQUALS(date.day, 9);
	TEST_ASSERT_EQUALS(date.month, 8);
	TEST_ASSERT_EQUALS(date.year, 2001 - 1900);
	TEST_ASSERT_EQUALS(date.dayOfTheWeek, 0);
	TEST_ASSERT_EQUALS(date.dayOfTheYear, 251);
}

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToDate2()
{
	modm::Date date;
	modm::UnixTime(1073741824UL).toDate(&date);
	
	TEST_ASSERT_EQUALS(date.second, 4);
	TEST_ASSERT_EQUALS(date.minute, 37);
	TEST_ASSERT_EQUALS(date.hour, 13);
	TEST_ASSERT_EQUALS(date.day, 10);
	TEST_ASSERT_EQUALS(date.month, 0);
	TEST_ASSERT_EQUALS(date.year, 2004 - 1900);
	TEST_ASSERT_EQUALS(date.dayOfTheWeek, 6);
	TEST_ASSERT_EQUALS(date.dayOfTheYear, 9);
}

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToDate3()
{
	modm::Date date;
	modm::UnixTime(1311738121UL).toDate(&date);
	
	TEST_ASSERT_EQUALS(date.second, 1);
	TEST_ASSERT_EQUALS(date.minute, 42);
	TEST_ASSERT_EQUALS(date.hour, 3);
	TEST_ASSERT_EQUALS(date.day, 27);
	TEST_ASSERT_EQUALS(date.month, 6);
	TEST_ASSERT_EQUALS(date.year, 2011 - 1900);
	TEST_ASSERT_EQUALS(date.dayOfTheWeek, 3);
	TEST_ASSERT_EQUALS(date.dayOfTheYear, 207);
}

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToDate4()
{
	modm::Date date;
	modm::UnixTime(1333329284UL).toDate(&date);
	
	TEST_ASSERT_EQUALS(date.second, 44);
	TEST_ASSERT_EQUALS(date.minute, 14);
	TEST_ASSERT_EQUALS(date.hour, 1);
	TEST_ASSERT_EQUALS(date.day, 2);
	TEST_ASSERT_EQUALS(date.month, 3);
	TEST_ASSERT_EQUALS(date.year, 2012 - 1900);
	TEST_ASSERT_EQUALS(date.dayOfTheWeek, 1);
	TEST_ASSERT_EQUALS(date.dayOfTheYear, 92);
}

// ----------------------------------------------------------------------------
void
TimeTest::testConversionToDate5()
{
	modm::Date date;
	modm::UnixTime(3141592653UL).toDate(&date);
	
	// 00:37:33 UTC on 21 July 2069
	TEST_ASSERT_EQUALS(date.second, 33);
	TEST_ASSERT_EQUALS(date.minute, 37);
	TEST_ASSERT_EQUALS(date.hour, 0);
	TEST_ASSERT_EQUALS(date.day, 21);
	TEST_ASSERT_EQUALS(date.month, 6);
	TEST_ASSERT_EQUALS(date.year, 2069 - 1900);
	TEST_ASSERT_EQUALS(date.dayOfTheWeek, 0);
	TEST_ASSERT_EQUALS(date.dayOfTheYear, 201);
}
