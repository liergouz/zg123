
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0212);
        set_name( "拳脚招架" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "02121"->can_perform(me);
        __DIR__ "02122"->can_perform(me);
        __DIR__ "02123"->can_perform(me);
        __DIR__ "02124"->can_perform(me);

}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 02121 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02122 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02123 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 02124 );
}

// 函数：重计属性
void recount_char( object me ) { USER_ENERGY_D->count_dp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［拳脚招架］提升空手时的防御力，每级提升 3 点\n";
}
