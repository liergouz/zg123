
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("�ɺ�����");
        set_picid_1(8650);
        set_picid_2(8650);

        set_level(120);
        set_value(98000);
        set_max_lasting(6399);
        set("cp", 230);
        set("pp", 130);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ɺ�����";
}
