
// �������ܷ�����ָ��
void can_perform( object me )
{
        //	ս��
        send_user( me,"%c%c%c%w%w%w%w%c%s",0xa5,5,4,00014,00015,00061,00900,4,"ս�� ���õ���һЩ�������ܺͶ����������Զ�������Զ�������ʹ�÷�����ʹ�����");
	//	׷��
        send_user( me,"%c%c%c%w%w%w%c%s",0xa5,5,3,00031,00032,00041,4,"׷�� �������ʹ�������ʦү����ʱ����Ҫ�õ���һЩ���ܡ�");
        //	����        	
        send_user( me,"%c%c%c%w%w%w%w%w%c%s",0xa5,5,5,00012,00051,00011,00021,00022,4,"���� ��Ҿ����õ���һЩ���ܺͶ�����������̯�����ﲶץ�����桢�ƿ�ʬ����׿�ʬ�塣");
        __DIR__ "00011"->can_perform(me);    	// ���棬��ط���λ
        
	__DIR__ "00014"->can_perform(me);	// �Զ�������
	__DIR__ "00015"->can_perform(me);     	// �Զ���������(����)
	   
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

// ������ɾ������ָ��
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
