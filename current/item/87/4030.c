
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ˮ����");
        set_picid_1(8709);
        set_picid_2(8709);

        set_level(30);
        set_value(5700);
        set_max_lasting(6699);
        set("dp", 20);
        set("pp", 20);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ˮ����";
}
