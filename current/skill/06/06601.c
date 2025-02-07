
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0660);
        set_name( "机关特殊技" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	send_user( me, "%c%c%w%w%c%w%w%s", 0x60, 3, 660, 6601, 0, 0, 0, "机关制作" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 1, "机关制作" );
}
