
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("�׽�����");
        set_picid_1(8614);
        set_picid_2(8614);

        set_level(80);
        set_value(48500);
        set_max_lasting(8499);
        set("cp", 0);
        set("pp", 80);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�׽�����";
}
