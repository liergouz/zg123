
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0413);
        set_name( "道法神通" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	__DIR__ "04130"->can_perform(me);
        __DIR__ "04131"->can_perform(me);
        __DIR__ "04132"->can_perform(me);
//        __DIR__ "04133"->can_perform(me);
        __DIR__ "04134"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
	send_user( me, "%c%w%w", 0x50, 0xffff, 04130 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04131 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04132 );
//        send_user( me, "%c%w%w", 0x50, 0xffff, 04133 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04134 );
}

// 函数：获取描述
string get_desc() 
{
        return "［道法神通］使用符纸召唤鬼卒、天兵、神将、僵尸协助战斗。\n";
}
