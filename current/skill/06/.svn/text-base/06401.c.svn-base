
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0640);
        set_name( "裁缝特殊技" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	send_user( me, "%c%c%w%w%c%w%w%s", 0x60, 3, 640, 6401, 0, 0, 0, "裁缝" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 1, "衣服" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 2, "帽子" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 3, "鞋" );
//	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 4, "项链" );
//	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 5, "腰带" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 6, "原料" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 7, "背包" );
}
