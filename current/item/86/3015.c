
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��ͭ����");
        set_picid_1(8604);
        set_picid_2(8604);

        set_level(15);
        set_value(3000);
        set_max_lasting(6499);
        set("cp", 0);
        set("pp", 10);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ͭ����";
}
