AutoScan
{
}

Core
{
}  

MissileHit
{
    print( "Hit by missle" )
}

FoundRobot
{
}

Dead
{
}

Pinged
{
    print( "Pinged from" _cldbearing "heading" _cldheading )
}

    regcldmissile( "MissileHit", 1 )
    regdtcrobot( "FoundRobot", 2 )
    regascan( "AutoScan", 3 )
    regping( "Pinged", 1 )

}
