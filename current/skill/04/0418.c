
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0418);
        set_name( "玄学正道" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04181"->can_perform(me);
        __DIR__ "04182"->can_perform(me);
        __DIR__ "04183"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04181 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04182 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04183 );
}
// 函数：重计属性
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_max_mp(me); 
	USER_ENERGY_D->count_pp(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［玄学正道］提升法力上限，每级提升 4 点；提升法术防御力，每级提升 2 点\n";
}
