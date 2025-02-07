
#include <ansi.h>
#include <action.h>
#include <skill.h>

#define THIS_PERFORM    00051
#define PF_NAME        "宠物捕捉"


// 函数：获取描述
string get_desc( object me ) 
{ 
        return "［" PF_NAME "］\n捕抓怪物训练成为自己的宠物，使用时必须消耗一条乾坤绳（杂货店有售）。\n"; 
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{        
        int rate, mp;
        object item;
	mapping mpInfo;
	
	if ( gone_time(me->get("capture_pet")) < 2 )
		return 1;
		
        if (me->get_level()+5<who->get_level())
        {
                send_user(me, "%c%s", '!', sprintf("您的等级不足以控制%s。", who->get_name()));
                return 1;        	
        }        
        if ( !who->is_badman() || who->can_not_catch() )
        {
                send_user(me, "%c%s", '!', "不能捕抓对方。");
                return 1;        	
        }
        mpInfo = "quest/pet"->get_beast_info(who->get_name());
        if ( !mpInfo )
        {
                send_user(me, "%c%s", '!', "不能捕抓对方。");
                return 1;        	
        }
        if (me->get_level()<mpInfo["level"])
        {
                send_user(me, "%c%s", '!', sprintf("您的等级不足以控制%s。", who->get_name()));
                return 1;        	
        }
        if (distance_between(me, who)>7)
        {
                printf( ECHO "您距离目标太远。" );
                return 1;        	
        }
        if( !objectp( item = present("乾坤绳", me, 1, MAX_CARRY*4) ) )
        {
                printf( ECHO "您得有乾坤绳才能使用“" PF_NAME "”。" );
                return 1;
        }    
        item->add_amount(-1);     	
        mp = 5 + who->get_level();	
	rate = 5 + (100 - who->get_hp()*100/who->get_max_hp() )/ 2;
	if( !who->get_max_damage() ) who->init_enemy_damage(me, 0);
	if(who->is_yutu())//月兔类，采用特殊捕捉方式
	{
		"quest/pet"->get_yutu(me,who);
		return 1;
	}
	if (random(100)>rate) 
	{
		send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 411, 1, OVER_BODY, PF_ONCE );      
		send_user(me, "%c%s", '!', "宠物捕捉失败");
		return 1;
	}
	if ( me->get_beast_amount() >= me->get_beast_max_amount() )
	{
		send_user(me, "%c%s", '!', "你不能携带更多的宠物了");
		return 1;
	}	
	if ( USER_BEAST_D->capture_beast(me,who) != 1 )
	{
		send_user(me, "%c%s", '!', "你不能捕捉宠物");
		return 1;
	}
	else
		send_user(me, "%c%s", '!', "你捕捉了" HIY+who->get_name());
	me->set("capture_pet",time());
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 412, 1, OVER_BODY, PF_ONCE );      
	who->remove_from_scene(FALL_ACT);
	who->before_destruct();
	destruct(who);
        return 1;
}

// 函数：获取指令类型
int get_perform_type() { return ON_CHAR_7; }

// 函数：能否使用指令
void can_perform( object me )
{
//	if ( USER_BEAST_D->can_perform(me) )
        	send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );	//显示捕捉指令
//        else
//        	send_user( me, "%c%w%w", 0x50, 0xffff,THIS_PERFORM);	//取消显示捕捉指令
}
