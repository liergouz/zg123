
inherit SKILL;

// 函数：构造处理
void create()
{
        set_number(0417);
        set_name( "顺天法咒" );
}

// 函数：能否特殊技
void can_perform( object me )
{
	__DIR__ "04172"->can_perform(me);
	__DIR__ "04173"->can_perform(me);
        __DIR__ "04171"->can_perform(me);
        __DIR__ "04174"->can_perform(me);
        __DIR__ "04175"->can_perform(me);
        __DIR__ "04176"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04171 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04172 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04173 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04174 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04175 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04176 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_dp(me); }

// 函数：获取描述
string get_desc()
{
        return "［顺天法咒］顺天神法，以辅助法术为主。\n";
}
