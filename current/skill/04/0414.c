
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0414);
        set_name( "逆天法咒" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	__DIR__ "04147"->can_perform(me);
	__DIR__ "04143"->can_perform(me);
	__DIR__ "04144"->can_perform(me);
	__DIR__ "04145"->can_perform(me);
	__DIR__ "04148"->can_perform(me);	
	__DIR__ "04141"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04143 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04144 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04145 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04147 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04148 );
}

// 函数：获取描述
string get_desc() 
{
        return "［逆天法咒］逆天邪法，以诅咒伤害打击对手。\n";
}
