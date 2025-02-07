
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0620);
        set_name( "锻造特殊技" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	send_user( me, "%c%c%w%w%c%w%w%s", 0x60, 3, 620, 6201, 0, 0, 0, "锻造" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 1, "拳套" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 2, "刀" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 3, "枪" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 4, "剑" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 5, "棍" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 6, "暗器" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 7, "原料" );
}
