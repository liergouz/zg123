
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ͭ����");
        set_picid_1(8604);
        set_picid_2(8604);

        set_level(15);
        set_value(3400);
        set_max_lasting(5299);
        set("cp", 0);
        set("pp", 17);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ͭ����";
}
