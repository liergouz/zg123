#include <ansi.h>
#include <item.h>
#include <effect.h>

// º¯Êý£ºÃüÁî´¦Àí
int main( object me, string arg )
{
	string *nTmp;
        if( !arg ) return 1;
	nTmp = explode(arg," ");
	switch(to_int(nTmp[0]))
	{
	default:
		break;
	case 0:	
		me->delete("buy_vip_package");				
		break;
	case 1:
		"/cmd/base/buyitem"->main(me, me->get("buy_vip_package"));
		break;
	case 37:
		if ( !is_god(me) )
			return ;
		me->set_save_2("vip_package.time",time());
		break;
	case 36:
		if ( !is_god(me) )
			return ;
		me->set("test_vip",to_int(nTmp[1]));
		"item/sell/0061"->give_item_to_user(me);
		me->delete("test_vip");
		break;
	}
}