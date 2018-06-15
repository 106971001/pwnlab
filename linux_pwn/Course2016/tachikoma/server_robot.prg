358
Autoscan
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
    print( "FoundRobot" )
}
pinged
{
    print( "Pinged from" _cldbearing "heading" _cldheading )
}
 
Dead
{
}

init
{
    print( "asd") 
    regping( "Pinged", 1 )     
    regdtcrobot( "FoundRobot", 2 )
    regascan( "AutoScan", 3 )
    regcldmissile( "MissileHit", 4 )
}
