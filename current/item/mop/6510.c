
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("�¸���֮��");
        set_picid_1(6523);
        set_picid_2(6523);
	set_no_give(1);
        set_level(0);
        set_value(1);
        set_max_lasting(10099);
        set("dp", 10);
        set("pp", 0);

        setup();

        set_gender(1);
        set_head_code(40);
}

// ��������ȡ����
string get_desc()
{
        return "���¸���ʹ�ã��޵ȼ����ơ����������ơ�";
}
