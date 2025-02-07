
// º¯Êý£ºÃüÁî´¦Àí
int main( object me, string arg )
{
	object who;
	string id, info, key, func;
/*
        if( abs( me->get_time("talk") - get_heart_timer(me) ) < 2 )    // 0.2 Ãë£¬ÐÄÌøÓÐÓ°Ïì
        {
                me->set_time( "talk", get_heart_timer(me) );
                notify( "ÇëÎðÆµ·±¶Ô»°¡£" );
                return 1;
        }
        me->set_time( "talk", get_heart_timer(me) );
*/
        if( me->is_store_open() )
        {
                notify( "ÄúÔÚ°ÚÌ¯£¬²»ÄÜÏÐÁÄ¡£" );
                return 1;
        }
        if( !arg ) return 1;

        if( sscanf(arg, "%s %s", id, info) != 2 )
        {
                if(     sscanf(arg, "%s.%s", key, info) == 2 
                &&      info
                &&    ( func = me->get_2( "do." + key ) ) )
                {
                        if( functionp(func) ) evaluate(func, info);
                        else send_user( me, "%c%s", ':', func );
                }
                else if( func = me->get_2( "do." + arg ) ) 
                {
                        if( functionp(func) ) evaluate(func);
                        else send_user( me, "%c%s", ':', func );
                }

                return 1;
        }

        if( !objectp( who = find_char(id) ) ) return 1;

        if( me->get_pay_money_buy_item()!=8 && !inside_screen_2(me, who) &&  !who->is_org_officer() )
        {
                notify( "Äú¾àÀë%sÌ«Ô¶ÁË¡£", who->get_name() );
                return 1;
        }

        if(     sscanf(info, "%s.%s", key, arg) == 2 
        &&      arg
        &&    ( func = who->get_2( "talk." + key ) ) )
        {
                me->to_front_eachother(who);
                if( functionp(func) ) evaluate(func, arg);
                else send_user( me, "%c%s", ':', func );
        }
        else if( func = who->get_2( "talk." + info ) ) 
        {
                me->to_front_eachother(who);
                if( functionp(func) ) evaluate(func);
                else send_user( me, "%c%s", ':', func );
        }
	return 1;
}
