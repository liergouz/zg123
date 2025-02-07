
#include <equip.h>

// 函数：命令处理
int main( object me, string arg )
{
	object obj;

        if( gone_time( me->get_time("remove") ) < 1 )    // 时间限制
        {
                me->set_time( "remove", time() );
                return 1;
        }
        if (me->get_perform("03191"))
        {
        	notify( "狂暴状态下不能更换装备" );
        	return 1;
        }
        if (me->get_perform("03192"))
        {
        	notify( "防御状态下不能更换装备" );
        	return 1;
        }        
        me->set_time( "remove", time() );

        if( arg ) switch( arg )
        {
               case "1" : me->remove_equip(HEAD_TYPE);  break;
               case "2" : me->remove_equip(NECK_TYPE);  break;
               case "3" : me->remove_equip(WEAPON_TYPE);  break;
               case "4" : me->remove_equip(ARMOR_TYPE);  break;
               case "5" : me->remove_equip(WAIST_TYPE);  break;
               case "6" : me->remove_equip(BOOTS_TYPE);  break;
               case "7" : me->remove_equip(HAND_TYPE);  break;
//               case "8" : me->remove_equip(FAMILY_TYPE);  break;
	       case "9" : me->remove_equip(BACK_TYPE);  break;
        }

        return 1;
}
