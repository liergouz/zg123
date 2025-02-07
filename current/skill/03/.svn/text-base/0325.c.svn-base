
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0325);
        set_name( "混元真气" );
}

// 函数：能否特殊技
void can_perform( object me )
{
//        __DIR__ "03251"->can_perform(me);
        __DIR__ "03252"->can_perform(me);
        __DIR__ "03253"->can_perform(me);
        __DIR__ "03254"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
//        send_user( me, "%c%w%w", 0x50, 0xffff, 03251 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03252 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03253 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 03254 );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_pp(me); 
	USER_ENERGY_D->count_max_mp(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［混元真气］提升法力上限，每级提升2点。提升法术防御力上限，每级提升1点。\n";    // level / 9.5 = level * 0.1
}
