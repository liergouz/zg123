
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("�ɻ�����");
        set_picid_1(8705);
        set_picid_2(8705);

        set_level(45);
        set_value(8750);
        set_max_lasting(8899);
        set("dp", 48);
        set("pp", 33);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ɻ�����";
}
