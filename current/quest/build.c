
// �����������б�
string *Quest = ({
        "�컯��",
        "���ĵ�",
        "�ȼ���",
        "���ĵ�",
        "������",

        "�ٶ�ɢ",
        "���ĵ�",
        "����ɢ",
});

int sizeof_quest = sizeof(Quest);

// ��������ȡ����
string get_quest( object who ) { return Quest[ random(sizeof_quest) ]; }
