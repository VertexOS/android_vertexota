// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2014, Oracle and/or its affiliates.

// Licensed under the Boost Software License version 1.0.
// http://www.boost.org/users/license.html

// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle

#include <iostream>

#ifndef BOOST_TEST_MODULE
#define BOOST_TEST_MODULE test_intersection_pointlike_pointlike
#endif

#ifdef BOOST_GEOMETRY_TEST_DEBUG
#define BOOST_GEOMETRY_DEBUG_TURNS
#define BOOST_GEOMETRY_DEBUG_SEGMENT_IDENTIFIER
#endif

#include <boost/test/included/unit_test.hpp>

#include "test_set_ops_pl_pl.hpp"

#include <boost/geometry/multi/geometries/multi_point.hpp>

typedef bg::model::point<double,2,bg::cs::cartesian>  point_type;
typedef bg::model::multi_point<point_type>  multi_point_type;



//===========================================================================
//===========================================================================
//===========================================================================


BOOST_AUTO_TEST_CASE( test_intersection_point_point )
{
#ifdef BOOST_GEOMETRY_TEST_DEBUG
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "*** POINT / POINT INTERSECTION ***" << std::endl;
    std::cout << std::endl;
#endif

    typedef point_type P;
    typedef multi_point_type MP;

    typedef test_set_op_of_pointlike_geometries
        <
            P, P, MP, bg::overlay_intersection
        > tester;

    tester::apply
        (from_wkt<P>("POINT(0 0)"),
         from_wkt<P>("POINT(1 1)"),
         from_wkt<MP>("MULTIPOINT()"),
         "ppi01");

    tester::apply
        (from_wkt<P>("POINT(0 0)"),
         from_wkt<P>("POINT(0 0)"),
         from_wkt<MP>("MULTIPOINT(0 0)"),
         "ppi02");
}


BOOST_AUTO_TEST_CASE( test_intersection_multipoint_point )
{
#ifdef BOOST_GEOMETRY_TEST_DEBUG
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "*** MULTIPOINT / POINT INTERSECTION ***" << std::endl;
    std::cout << std::endl;
#endif

    typedef point_type P;
    typedef multi_point_type MP;

    typedef test_set_op_of_pointlike_geometries
        <
            MP, P, MP, bg::overlay_intersection
        > tester;

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0)"),
         from_wkt<P>("POINT(1 1)"),
         from_wkt<MP>("MULTIPOINT()"),
         "mppi01");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0)"),
         from_wkt<P>("POINT(0 0)"),
         from_wkt<MP>("MULTIPOINT(0 0)"),
         "mppi02");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0,0 0)"),
         from_wkt<P>("POINT(1 1)"),
         from_wkt<MP>("MULTIPOINT()"),
         "mppi03");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0,0 0)"),
         from_wkt<P>("POINT(0 0)"),
         from_wkt<MP>("MULTIPOINT(0 0)"),
         "mppi04");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0,0 0,1 0)"),
         from_wkt<P>("POINT(1 1)"),
         from_wkt<MP>("MULTIPOINT()"),
         "mppi05");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0,0 0,1 0)"),
         from_wkt<P>("POINT(1 0)"),
         from_wkt<MP>("MULTIPOINT(1 0)"),
         "mppi06");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0,0 0,1 0)"),
         from_wkt<P>("POINT(0 0)"),
         from_wkt<MP>("MULTIPOINT(0 0)"),
         "mppi07");

    tester::apply
        (from_wkt<MP>("MULTIPOINT()"),
         from_wkt<P>("POINT(0 0)"),
         from_wkt<MP>("MULTIPOINT()"),
         "mppi08");
}


BOOST_AUTO_TEST_CASE( test_intersection_multipoint_multipoint )
{
#ifdef BOOST_GEOMETRY_TEST_DEBUG
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "*** MULTIPOINT / MULTIPOINT INTERSECTION ***" << std::endl;
    std::cout << std::endl;
#endif

    typedef multi_point_type MP;

    typedef test_set_op_of_pointlike_geometries
        <
            MP, MP, MP, bg::overlay_intersection
        > tester;

    tester::apply
        (from_wkt<MP>("MULTIPOINT(2 2,3 3,0 0,0 0,2 2,1 1,1 1,1 0,1 0)"),
         from_wkt<MP>("MULTIPOINT(1 0,1 1,1 1,1 1)"),
         from_wkt<MP>("MULTIPOINT(1 0,1 1,1 1,1 1)"),
         "mpmpi01");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0,1 1,1 0,1 1)"),
         from_wkt<MP>("MULTIPOINT(1 0,0 0,1 1,0 0)"),
         from_wkt<MP>("MULTIPOINT(0 0,1 1,1 0,1 1)"),
         from_wkt<MP>("MULTIPOINT(1 0,0 0,1 1,0 0)"),
         "mpmpi02");

    tester::apply
        (from_wkt<MP>("MULTIPOINT()"),
         from_wkt<MP>("MULTIPOINT(1 0,0 0,1 1,0 0)"),
         from_wkt<MP>("MULTIPOINT()"),
         "mpmpi03");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0,1 1,1 0,1 1)"),
         from_wkt<MP>("MULTIPOINT()"),
         from_wkt<MP>("MULTIPOINT()"),
         "mpmpi04");

    tester::apply
        (from_wkt<MP>("MULTIPOINT()"),
         from_wkt<MP>("MULTIPOINT()"),
         from_wkt<MP>("MULTIPOINT()"),
         "mpmpi05");

    tester::apply
        (from_wkt<MP>("MULTIPOINT(0 0,1 0,2 0,3 0,0 0,1 0,2 0)"),
         from_wkt<MP>("MULTIPOINT(0 1,0 2,1 0,0 0,2 0)"),
         from_wkt<MP>("MULTIPOINT(1 0,0 0,2 0)"),
         "mpmpi06");
}

