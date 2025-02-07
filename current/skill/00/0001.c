
// 函数：能否特殊指令
void can_perform( object me )
{
        //	战斗
        send_user( me,"%c%c%c%w%w%w%w%c%s",0xa5,5,4,00014,00015,00061,00900,4,"战斗 常用到的一些基础技能和动作，包括自动射击、自动攻击、使用法宝和使用信物。");
	//	追查
        send_user( me,"%c%c%c%w%w%w%c%s",0xa5,5,3,00031,00032,00041,4,"追查 玩家在做使命任务和师爷任务时必须要用到的一些技能。");
        //	动作        	
        send_user( me,"%c%c%c%w%w%w%w%w%c%s",0xa5,5,5,00012,00051,00011,00021,00022,4,"动作 玩家经常用到的一些功能和动作，包括摆摊、宠物捕抓、跟随、推开尸体和抛开尸体。");
        __DIR__ "00011"->can_perform(me);    	// 跟随，务必放首位
        
	__DIR__ "00014"->can_perform(me);	// 自动物理攻击
	__DIR__ "00015"->can_perform(me);     	// 自动法术攻击(暗器)
	   
        __DIR__ "00012"->can_perform(me);
//        __DIR__ "00013"->can_perform(me);

        __DIR__ "00021"->can_perform(me);
        __DIR__ "00022"->can_perform(me);

        __DIR__ "00031"->can_perform(me);
        __DIR__ "00032"->can_perform(me);

        __DIR__ "00041"->can_perform(me);
        __DIR__ "00051"->can_perform(me);
        __DIR__ "00061"->can_perform(me);
}

// 函数：删除特殊指令
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 00011 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 00012 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 00013 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 00014 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 00015 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 00021 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 00022 );

        send_user( me, "%c%w%w", 0x50, 0xffff, 00031 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 00032 );

        send_user( me, "%c%w%w", 0x50, 0xffff, 00041 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 00051 );
}
