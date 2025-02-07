
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0650);
        set_name( "石刻特殊技" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	send_user( me, "%c%c%w%w%c%w%w%s", 0x60, 3, 650, 6501, 0, 0, 0, "石刻制作" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 1, "镶嵌制作" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 2, "项链制作" );	
}
