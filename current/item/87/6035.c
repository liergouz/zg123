
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("�׻�����");
        set_picid_1(8709);
        set_picid_2(8709);

        set_level(35);
        set_value(9750);
        set_max_lasting(5799);
        set("dp", 20);
        set("pp", 35);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�׻�����";
}
