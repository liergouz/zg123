
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��ս����");
        set_picid_1(8708);
        set_picid_2(8708);

        set_level(30);
        set_value(5000);
        set_max_lasting(7599);
        set("dp", 28);
        set("pp", 15);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ս����";
}
