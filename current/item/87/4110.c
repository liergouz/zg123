
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ե����");
        set_picid_1(8712);
        set_picid_2(8712);

        set_level(110);
        set_value(24100);
        set_max_lasting(11499);
        set("dp", 100);
        set("pp", 100);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Ե����";
}
