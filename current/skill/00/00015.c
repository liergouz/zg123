
#include <ansi.h>
#include <skill.h>
#include <equip.h>

#define THIS_PERFORM    00015
#define PF_START       "00015"
#define PF_NAME        "自动射击"

// 函数：获取描述
string get_desc( object me ) 
{ 
	if (me->get_fam_name()=="唐门")
        	return "［自动射击］\n利用暗器攻击远处一个敌对目标。\n"; 
        else
        	return "［" PF_NAME "］\n利用法剑攻击远处一个敌对目标。\n"; 
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
	string family, name;
	object item;
	family = me->get_fam_name();
/*	
	if (family=="禁卫军" || family=="桃花源" || family=="" || family==0 )
	{
		printf( ECHO "您所在的门派没有“" PF_NAME "”。" );
		return 1;
	}
*/	
	if (me->get_attack_move()==1 && me->get_enemy())
	{
		me->set_enemy(0);
		printf(ECHO "你中止了“" PF_NAME "”。" );
		return 1;
	}	
	item = me->get_equip(WEAPON_TYPE);
/*	
	if ( family=="蜀山" && (!item||item->get_weapon_type()!=SWORD) )
	{
		printf( ECHO "您需要装备剑才能使用“" PF_NAME "”。" );
		return 1;		
	}			
*/	
	if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 1;    // 执行成功
	me->set_enemy(0);
        me->start_fight(who);
        if( who->is_npc() ) who->start_fight(me);    // 玩家需主动还击
	me->set_attack_move(1);
	printf( ECHO "使用“" PF_NAME "”。" );	
        return 1;
}

// 函数：获取指令类型
int get_perform_type() { return ON_CHAR_7; }

// 函数：能否使用指令
void can_perform( object me )
{
	send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
