
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0680);
        set_name( "药师特殊技" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	send_user( me, "%c%c%w%w%c%w%w%s", 0x60, 3, 680, 6801, 0, 0, 0, "药材加工" );
	send_user( me, "%c%c%w%w%s", 0x60, 4, get_number(), 1, "药材加工" );
}
