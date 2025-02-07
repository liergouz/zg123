
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0363);
        set_name( "唐门毒经" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	__DIR__ "03636"->can_perform(me);
	__DIR__ "03634"->can_perform(me);
	__DIR__ "03633"->can_perform(me);
	__DIR__ "03637"->can_perform(me);
	
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 03636 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03634 );
	send_user( me, "%c%w%w", 0x50, 0xffff, 03633 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03637 );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
        USER_ENERGY_D->count_dp(me);
}

// 函数：获取描述
string get_desc() 
{
        return "［唐门毒经］提升玩家装备暗器时的防御力，每级提升0.8点。 \n";
}
