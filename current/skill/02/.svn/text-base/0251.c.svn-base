
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0251);
        set_name( "疯魔棍法" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	__DIR__ "02510"->can_perform(me);
	__DIR__ "02514"->can_perform(me);
	__DIR__ "02513"->can_perform(me);
	__DIR__ "02516"->can_perform(me);
	__DIR__ "02517"->can_perform(me);
	__DIR__ "02512"->can_perform(me);
	__DIR__ "02515"->can_perform(me);   
}

// 函数：删除特殊技
void remove_perform( object me )
{
//        send_user( me, "%c%w%w", 0x50, 0xffff, 02511 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02512 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02513 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02514 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02515 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02516 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02517 );
}

// 函数：重计属性
void recount_char( object me ) { }

// 函数：获取描述
string get_desc() 
{
        return "［疯魔棍法］禁卫军棍法特殊技。\n";
}
